import java.util.ArrayList;
import java.util.HashMap;
import java.util.Stack;

/**
 * Created by Nadith on 5/6/2016.
 */
public class trip {

    String routes;
    int cost;

    trip(String city){

        this.routes =city;
    }

    public String toString(){

        String temp=" Routes: ("+routes + ") Cost: ( " +cost +")\n";
            return temp;

    }
}
