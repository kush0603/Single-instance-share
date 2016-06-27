package com.example.amirulislam.nabilsproject;

import java.io.Serializable;

/**
 * Created by Amirul Islam on 15-05-2016.
 */
public class Child implements Serializable {

    int child_id;
    String child_name;
    String password;
    int account_id;

    public int getChild_id() {
        return child_id;
    }

    public void setChild_id(int child_id) {
        this.child_id = child_id;
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

    public int getAccount_id() {
        return account_id;
    }

    public void setAccount_id(int account_id) {
        this.account_id = account_id;
    }
}
