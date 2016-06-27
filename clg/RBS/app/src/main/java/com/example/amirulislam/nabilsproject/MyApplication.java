package com.example.amirulislam.nabilsproject;

import android.app.Application;

/**
 * Created by Amirul Islam on 02-05-2016.
 */
public class MyApplication extends Application {

    public String getHour() {
        return hour;
    }

    public void setHour(String hour) {
        this.hour = hour;
    }

    public String getMinute() {
        return minute;
    }

    public void setMinute(String minute) {
        this.minute = minute;
    }

    public String getQuantity() {
        return quantity;
    }

    public void setQuantity(String quantity) {
        this.quantity = quantity;
    }

    private String hour;
    private String minute;
    private String quantity;

    public String geturlServer() {
        return urlServer;
    }

    public void seturlServer(String ipAddress) {
        this.urlServer = "http://"+ipAddress+":5000/send_data";
        Config.DATA_SEND_URL=this.urlServer;

    }

    private String urlServer;



}