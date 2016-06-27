package com.example.amirulislam.nabilsproject;

import java.io.Serializable;

/**
 * Created by Amirul Islam on 15-05-2016.
 */
public class Merchant implements Serializable {
    String merchantIDPhoto;
    String username;
    String password;
    String merchantName;
    String category;
    int amount;
    String paymentGateway;
    String paymentAccount;


    public String getMerchantIDPhoto() {
        return merchantIDPhoto;
    }

    public void setMerchantIDPhoto(String merchantIDPhoto) {
        this.merchantIDPhoto = merchantIDPhoto;
    }

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public String getMerchantName() {
        return merchantName;
    }

    public void setMerchantName(String merchantName) {
        this.merchantName = merchantName;
    }

    public String getCategory() {
        return category;
    }

    public void setCategory(String category) {
        this.category = category;
    }

    public int getAmount() {
        return amount;
    }

    public void setAmount(int amount) {
        this.amount = amount;
    }

    public String getPaymentGateway() {
        return paymentGateway;
    }

    public void setPaymentGateway(String paymentGateway) {
        this.paymentGateway = paymentGateway;
    }

    public String getPaymentAccount() {
        return paymentAccount;
    }

    public void setPaymentAccount(String paymentAccount) {
        this.paymentAccount = paymentAccount;
    }





}
