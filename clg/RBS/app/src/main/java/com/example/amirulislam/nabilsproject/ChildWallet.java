package com.example.amirulislam.nabilsproject;

import java.io.Serializable;

/**
 * Created by Amirul Islam on 14-05-2016.
 */
public class ChildWallet implements Serializable {


    int child_wallet_id;

    public double getLat() {
        return lat;
    }

    public void setLat(double lat) {
        this.lat = lat;
    }

    public double getLon() {
        return lon;
    }

    public void setLon(double lon) {
        this.lon = lon;
    }

    String username;
    String child_name;
    String password;
    String parent_username;
    int wallet_limit;
    int radius;
    double lat;
    double lon;
    int amount;


    public int getChild_wallet_id() {
        return child_wallet_id;
    }

    public void setChild_wallet_id(int child_wallet_id) {
        this.child_wallet_id = child_wallet_id;
    }

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public String getChild_name() {
        return child_name;
    }

    public void setChild_name(String child_name) {
        this.child_name = child_name;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public String getParent_username() {
        return parent_username;
    }

    public void setParent_username(String parent_username) {
        this.parent_username = parent_username;
    }

    public int getWallet_limit() {
        return wallet_limit;
    }

    public void setWallet_limit(int wallet_limit) {
        this.wallet_limit = wallet_limit;
    }

    public int getRadius() {
        return radius;
    }

    public void setRadius(int radius) {
        this.radius = radius;
    }



    public int getAmount() {
        return amount;
    }

    public void setAmount(int amount) {
        this.amount = amount;
    }
}
