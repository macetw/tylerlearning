package us.softwareworks.domain;

import com.google.gson.Gson;
import com.google.gson.GsonBuilder;

public class JsonDisplay {
    public static String showJson(Object object) {
        Gson gson = new GsonBuilder().create();
        String json = gson.toJson(object);
        System.out.println(json);

        return json;

    }
}
