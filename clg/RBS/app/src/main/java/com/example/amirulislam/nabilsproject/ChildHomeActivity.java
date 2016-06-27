package com.example.amirulislam.nabilsproject;

import android.content.Intent;
import android.graphics.Bitmap;
import android.graphics.Color;
import android.os.AsyncTask;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.Toast;

import com.google.zxing.BarcodeFormat;
import com.google.zxing.WriterException;
import com.google.zxing.common.ByteMatrix;
import com.google.zxing.qrcode.QRCodeWriter;

import org.apache.http.NameValuePair;
import org.apache.http.message.BasicNameValuePair;
import org.json.JSONObject;

import java.util.ArrayList;
import java.util.List;

public class ChildHomeActivity extends AppCompatActivity {

    com.example.amirulislam.nabilsproject.JSONParser jsonParser=new com.example.amirulislam.nabilsproject.JSONParser();
    ChildWallet childWalletAccountDetails=null;

    EditText walletBalanceTextBox=null;
    EditText payableAmountTextBox=null;
    Button submitCoins=null;
  //  ImageView QRCodeImageView=null;





    @Override
    protected void onCreate(Bundle savedInstanceState) {

        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_child_home);

        getDetailsFromPreviousIntent();
        walletBalanceTextBox=(EditText)findViewById(R.id.walletbalancetextbox);
        payableAmountTextBox=(EditText)findViewById(R.id.payableamounttextbox);
       // generateQRCodeButton=(Button)findViewById(R.id.generateQRbutton);
        submitCoins=(Button)findViewById(R.id.payCoins);



        walletBalanceTextBox.setText(Integer.toString(childWalletAccountDetails.getAmount()));

        //add the button listener
        submitCoins.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                int prev_coins=childWalletAccountDetails.getAmount();
                int payable_coins=Integer.parseInt(payableAmountTextBox.getText().toString());
                int updated_coins_childs_wallet=prev_coins-payable_coins;
                int child_wallet_id=childWalletAccountDetails.getChild_wallet_id();
                String merchantId="baristaID";
                List<NameValuePair> params = new ArrayList<NameValuePair>();
                //for merchant
                params.add(new BasicNameValuePair("merchant_id", merchantId));
                params.add(new BasicNameValuePair("add_coin", Integer.toString(payable_coins)));
                //for child wallet
                params.add(new BasicNameValuePair("child_wallet_id", Integer.toString(child_wallet_id)));
                params.add(new BasicNameValuePair("amount", Integer.toString(updated_coins_childs_wallet)));
                UpdateMerchantChildWalletAccount UpdateMerchantChildWalletAccountAsyncAct=new UpdateMerchantChildWalletAccount();
                UpdateMerchantChildWalletAccountAsyncAct.execute(params);
                /*QRCodeWriter writer = new QRCodeWriter();
                ImageView img = (ImageView)findViewById(R.id.QRImageView);
                try {
                    String childWalletId=Integer.toString(childWalletAccountDetails.getChild_wallet_id());
                    String amountPayable=payableAmountTextBox.getText().toString();
                    ByteMatrix bitMatrix = writer.encode("rbscoin?"+childWalletId+"?"+amountPayable, BarcodeFormat.QR_CODE, 512, 512);
                    int width = 512;
                    int height = 512;
                    Bitmap bmp = Bitmap.createBitmap(width, height, Bitmap.Config.RGB_565);
                    for (int x = 0; x < width; x++) {
                        for (int y = 0; y < height; y++) {
                            if (bitMatrix.get(x, y)==0)
                                bmp.setPixel(x, y, Color.BLACK);
                            else
                                bmp.setPixel(x, y, Color.WHITE);
                        }
                    }
                    img.setImageBitmap(bmp);
                } catch (WriterException e) {
                    //Log.e("QR ERROR", ""+e);
                }
*/
            }
        });
    }

    protected void getDetailsFromPreviousIntent(){
        Intent childHomeIntent=getIntent();
        childWalletAccountDetails=(ChildWallet)childHomeIntent.getSerializableExtra("childWalletDetails");
    }


    private class UpdateMerchantChildWalletAccount extends AsyncTask<List<NameValuePair>, Void, Boolean> {
        protected Boolean doInBackground(List<NameValuePair> ... paramsList) {
            boolean updateResult = false;
            for(List<NameValuePair>  params:paramsList) {
                JSONObject json = jsonParser.makeHttpRequest(Config.URL_UPDATE_MERCHANT_CHILD_WALLET_ACCOUNT, "GET", params);
                String resultWord = null;
                try {
                    resultWord = json.getString("result");
                    Log.d("Msg", json.getString("result"));
                    if(resultWord.equals("success")){
                        return true;
                    }
                    else {
                        updateResult=false;
                    }
                }
                catch(Exception e){
                    e.getMessage();
                }
            }
            return updateResult;
        }
        protected void onPostExecute(Boolean result) {
            if(result){
                Toast.makeText(ChildHomeActivity.this, "Successfully paid the vendor", Toast.LENGTH_SHORT).show();
                finish();
            }
            else{
            }
        }
    }




}
