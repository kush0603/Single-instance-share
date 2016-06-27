package com.example.amirulislam.nabilsproject;

import java.io.Serializable;

/**
 * Created by Amirul Islam on 14-05-2016.
 */
public class Account implements Serializable {
    int account_id;
    String account_name;
    int account_balance;


    public int getAccount_id() {
        return account_id;
    }

    public void setAccount_id(int account_id) {
        this.account_id = account_id;
    }

    public String getAccount_name() {
        return account_name;
    }

    public void setAccount_name(String account_name) {
        this.account_name = account_name;
    }

    public int getAccount_balance() {
        return account_balance;
    }

    public void setAccount_balance(int account_balance) {
        this.account_balance = account_balance;
    }
}
