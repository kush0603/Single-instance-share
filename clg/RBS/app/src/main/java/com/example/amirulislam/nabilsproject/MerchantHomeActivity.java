package com.example.amirulislam.nabilsproject;

import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.widget.Button;
import android.widget.TextView;

public class MerchantHomeActivity extends AppCompatActivity {


    Button scanQRCodeButton;
    TextView merchantWalletBalance;
    Merchant merchantWalletAccountDetail;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_merchant_home);
        //scanQRCodeButton=(Button)findViewById(R.id.ScanQRCodeButton);
        merchantWalletBalance=(TextView)findViewById(R.id.walletBalanceMerchant);
        getDetailsFromPreviousIntent();
        merchantWalletBalance.setText(""+merchantWalletAccountDetail.getAmount());



        //now the scanning of the QRCode





    }
    protected void getDetailsFromPreviousIntent(){
        Intent merchantHomeIntent=getIntent();
        merchantWalletAccountDetail=(Merchant)merchantHomeIntent.getSerializableExtra("merchantWalletAccountDetail");




    }
}
