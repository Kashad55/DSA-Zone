import java.util.*;
public class MapsIntro {
    public static void main(String[] args) {
        Map<String, String> mp = new HashMap<>();
        mp.put("us", "United States");
        mp.put("in", "India");
        // mp.put("in", "India2"); //if key present, put() updates new value
        mp.put("en", "England");  //store unique keys
        System.out.println(mp);
        System.out.println(mp.get("in"));
        System.out.println(mp.containsValue("India2"));
        mp.remove("en");
        System.out.println(mp);
        System.out.println(mp.containsKey("usa"));

        Set<String> keys = mp.keySet();
        // ArrayList<String> keys = new ArrayList<>(mp.keySet());   //we can insert any Collection into another Collection
        System.out.println("Keys = "+keys);

        Collection<String> values = mp.values();
        System.out.println(values);

        Set<Map.Entry<String, String>> entries = mp.entrySet();
        for(Map.Entry<String, String> e : entries){
            System.out.println(e.getKey()+", "+e.getValue());
        }
        System.out.println(entries);
    }
}
