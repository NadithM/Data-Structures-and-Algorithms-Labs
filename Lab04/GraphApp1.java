
import java.io.FileNotFoundException;
import java.util.*;
import java.util.concurrent.TimeUnit;



public class GraphApp1 {
	private final static String fileName = "data.txt";
	private static List<String> wantedplaces = new ArrayList<String>();
	private static List<Integer> numbers = new ArrayList<Integer>();

	private static HashMap<String, String> colour = new HashMap<>();
	public static HashMap<String, Integer> nooftime = new HashMap<>();
	private static HashMap<String, Integer> sizer = new HashMap<>();
	private static Queue<String> finalmap = new LinkedList<>();
	private static Queue<String> finalmapcopy = new LinkedList<>();
	private static Queue<String> finalone = new LinkedList<>();

	private static HashMap<String, trip> data = new HashMap<>();
	private static Queue<String> queue = new LinkedList<>();

	public static void main(String[] args) {
		try {
			Graph initialGraph = new Graph(fileName);
			System.out.println(initialGraph);
			long startTime = System.currentTimeMillis();


			// Give the places you wanted to go .First one Should be where you start & end
			String places = "Colombo Anuradhapura Trincomalee Kandy Galle NuwaraEliya Jaffna Arugambay Pinnawala Yala\n";
			String[] pl = places.split(" ");

			for (String rl : pl) {
				wantedplaces.add(rl);
			}
			for (Map.Entry<String, List<Graph.neighbor>> entry : initialGraph.adjacencyList.entrySet()) {
				String key = entry.getKey();
				colour.put(key, "white");
				data.put(key, new trip(pl[0]));
			}
			Algo(initialGraph, pl[0]);


			System.out.print("\nYour route is :\n\n");
			for (Map.Entry<String, trip> entry : data.entrySet()) {
				trip path = entry.getValue();
				sizer.put(path.routes, path.routes.split(" ").length);
			}

			TreeMap<String, Integer> sortedMap = sortMapByValue(sizer);


			for (Map.Entry<String, Integer> entry : sortedMap.entrySet()) {

				String key = entry.getKey();
				String[] arr2 = key.split(" ");
				key = arr2[arr2.length - 1];
				trip path = data.get(key);
				//System.out.print(wantedplaces.toString() +"wow \n");
				if (wantedplaces.contains(key)) {

					for (String tem : arr2) {

						if (wantedplaces.contains(tem)) wantedplaces.remove(tem);
					}


					finalmap.add(path.routes);
					//System.out.println(path.routes);

					//System.out.print("\n");
				}


			}


			int s=0,d=0;

			for(String temp6:finalmap){
				s++;
				if(numbers.contains(s))continue;

				String [] arr3=temp6.split(" ");
					d=0;
				//System.out.println(arr3[arr3.length-1]);

				for(String temp7:finalmap){
					d++;


					if(numbers.contains(d) || d==s) continue;

					String [] str2=temp7.split(" ");

					//System.out.println("res:"+arr3[arr3.length-1]+":"+str2[str2.length-1]+":"+initialGraph.isConnected(arr3[arr3.length-1],str2[str2.length-1]));
					if(initialGraph.isConnected(arr3[arr3.length-1],str2[str2.length-1])){


						String[] arr = temp7.split(" ");

						String build=" ";
						for (int h = 0; h < arr.length ; h++) {
							build=build + arr[arr.length - 1 - h]+" ";

						}

						finalone.add(temp6+build);

						numbers.add(d);
						numbers.add(s);

						break;
					};





				}

			}

			d=0;
			for(String temp7:finalmap){
				d++;


				if(numbers.contains(d) ) continue;

				else {

					String [] arr=temp7.split(" ");
					String build=" ";
					for (int h = 0; h < arr.length-1 ; h++) {
						build=build + arr[arr.length - 2 - h]+" ";

					}

					finalone.add(temp7+build);
				}


			}

		for(String r:finalone) {

			String [] arr2=r.split(" ");
			for (int h = 0; h < arr2.length - 1; h++) {
				String ky3 = null;
				Integer vl3 = 0;
				String pat = arr2[h] + " " + arr2[h + 1];
				for (Map.Entry<String, Integer> entry3 : nooftime.entrySet()) {
					ky3 = entry3.getKey();
					vl3 = entry3.getValue();

					if (ky3.contains(pat)) {
						vl3++;
						break;
					}

				}
				nooftime.remove(ky3);
				nooftime.put(ky3, vl3);

			}
		}


			for(String t: finalone){

				System.out.println(t);

			}

			int sumation = 0;
			for (Map.Entry<String, Integer> entry3 : nooftime.entrySet()) {
				String ky3 = entry3.getKey();
				int vl3 = entry3.getValue();

				if (vl3 == 0) {

					continue;
				} else {


					String[] twocity = ky3.split("/");
					String[] cit2 = twocity[0].split(" ");
					List<Graph.neighbor> temp5 = initialGraph.getEdges(cit2[0]);

					for (Graph.neighbor tr : temp5) {

						if (tr.vertex.equals(cit2[1])) {

							sumation = sumation + ((tr.weight + (tr.weight + (tr.weight * (( vl3 - 1))))) * ( vl3) / 2);

							//System.out.println("__________________________________________");

							//System.out.println(twocity[0]+" "+sumation +"   =="+((tr.weight + (tr.weight + (tr.weight * (( vl3 - 1))))) * ( vl3) / 2));
							//System.out.println("__________________________________________");

							break;

						}

					}



				}

			}


			System.out.print("\nFull Cost :" + sumation + " " + "Have a safe Journey...:D\n");

			//System.out.println("how many times a path used\n");
			//System.out.println("__________________________________________");

			//System.out.println(nooftime.toString());

			//System.out.println("__________________________________________");

			//System.out.print("\nHere are some usefull information about path and cost :\n\n");

			//System.out.print(data.toString() + "\n\n");




			long endTime = System.currentTimeMillis();

			// Calculate & Print the time taken by the algorithm/application
			long duration = (endTime - startTime);
			System.out.print("The execution of this program took: ");
			System.out.println(String.format("%d min, %d sec",
					TimeUnit.MILLISECONDS.toMinutes(duration),
					TimeUnit.MILLISECONDS.toSeconds(duration) -
							TimeUnit.MINUTES.toSeconds(TimeUnit.MILLISECONDS.toMinutes(duration))
			));


		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}


	public static void Algo(Graph initialGraph, String town) {

		queue.add(town);
		while (!queue.isEmpty()) {
			String ky = queue.remove();

			List<Graph.neighbor> edges = initialGraph.getEdges(ky);

			try {
				for (Graph.neighbor temp : edges) {
					if (colour.get(temp.vertex).equals("white")) {
						colour.put(temp.vertex, "gray");

						trip te = data.get(temp.vertex);
						trip tek = data.get(ky);

						te.cost = tek.cost + temp.weight;
						te.routes = tek.routes + " " + temp.vertex;
						queue.add(temp.vertex);

					}


				}
				colour.put(ky, "black");
			} catch (Exception e) {

				e.printStackTrace();
			}
		}

	}

	private static boolean isdiffrentpath(String key1, String key2) {

		trip temp1 = data.get(key1);
		trip temp2 = data.get(key2);

		String[] arr = temp1.routes.split(" ");
		String[] arr1 = temp2.routes.split(" ");
		boolean flag = true;
		boolean flag1 = true;

		for (String t : arr) {

			if (!temp2.routes.contains(t)) {

				flag = false;

				break;
			}
			;
		}

		for (String t : arr1) {

			if (!temp1.routes.contains(t)) {

				flag1 = false;

				break;
			}
		}


		if (!flag || !flag1) {

			return true;
		} else return false;

	}

	public static TreeMap<String, Integer> sortMapByValue(HashMap<String, Integer> map) {
		Comparator<String> comparator = new ValueComparator(map);

		TreeMap<String, Integer> result = new TreeMap<String, Integer>(comparator);
		result.putAll(map);
		return result;
	}

}