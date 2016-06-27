package com.example.amirulislam.nabilsproject;

import android.content.Intent;
import android.os.AsyncTask;
import android.os.Bundle;
import android.os.StrictMode;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.Toast;

import org.apache.http.NameValuePair;
import org.apache.http.message.BasicNameValuePair;
import org.json.JSONArray;
import org.json.JSONObject;

import java.util.ArrayList;
import java.util.List;


public class MainActivity extends AppCompatActivity {


    //the jsonparser
    com.example.amirulislam.nabilsproject.JSONParser jsonParser=new com.example.amirulislam.nabilsproject.JSONParser();



    EditText usernametextview;
    EditText passwordtextview;
    EditText ipAddressServer;
    Button submitButton;

    private RadioGroup radioUserTypeGroup;
    private RadioButton radioUserTypeButton;
    int userType=999;
    String username=null;
    String password=null;



    //the three values to be used
    public static String hour=null;
    public static String min=null;
    public static String quantity=null;



    //the arrayList containing wallet ids
    ArrayList<String> walletArrayList=null;




    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);


        StrictMode.ThreadPolicy policy = new StrictMode.ThreadPolicy.Builder().permitAll().build();
        StrictMode.setThreadPolicy(policy);



        setContentView(R.layout.activity_main);

        usernametextview=(EditText)findViewById(R.id.usernametextbox);
        passwordtextview=(EditText)findViewById(R.id.passwordtextbox);
       // ipAddressServer=(EditText)findViewById(R.id.ipaddresstextbox);



        submitButton=(Button)findViewById(R.id.btn_login);
        //declare the usergroup
        radioUserTypeGroup=(RadioGroup)findViewById(R.id.radioGroupUserType);



        //listener for submit button
        submitButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                //get the usertype
                int selectedId=radioUserTypeGroup.getCheckedRadioButtonId();
                radioUserTypeButton=(RadioButton)findViewById(selectedId);
                //Toast.makeText(MainActivity.this,radioUserTypeButton.getText(),Toast.LENGTH_SHORT).show();
                //set 0 for parent
                //1 for child
                username=usernametextview.getText().toString();
                password=passwordtextview.getText().toString();

                //populate parameters for request
                List<NameValuePair> params = new ArrayList<NameValuePair>();
                params.add(new BasicNameValuePair("name", username));
                params.add(new BasicNameValuePair("pass", password));



                if(radioUserTypeButton.getText().equals("Parent")){
                    userType=0;
                    params.add(new BasicNameValuePair("type", Integer.toString(userType)));
                    LoginThroughServerReturnAccount loginAsyncActivity=new LoginThroughServerReturnAccount();
                    Toast.makeText(MainActivity.this, "calling async", Toast.LENGTH_SHORT).show();
                    loginAsyncActivity.execute(params);

                }
                else if(radioUserTypeButton.getText().equals("Child")){
                    userType=1;


                    /*Intent childHomeActivityIntent = new Intent(getApplicationContext(), ChildHomeActivity.class);
                    startActivity(childHomeActivityIntent);*/


                    params.add(new BasicNameValuePair("type", Integer.toString(userType)));
                    LoginThroughServerReturnChild loginAsyncActivity=new LoginThroughServerReturnChild();
                    loginAsyncActivity.execute(params);


                }
                else if(radioUserTypeButton.getText().equals("Merchant")){

                    userType=3;
                    params.add(new BasicNameValuePair("type", Integer.toString(userType)));
                    LoginThroughServerReturnMerchant loginAsyncActivity=new LoginThroughServerReturnMerchant();
                    loginAsyncActivity.execute(params);
                }






                //finish();


/*
                //send request as a json object
                JSONObject json = jsonParser.makeHttpRequest(Config.URL_USER_LOGIN, "GET", params);
                Toast.makeText(MainActivity.this,"data sent",Toast.LENGTH_SHORT).show();
                String resultWord=null;

                //deal with the result
                try {
                    resultWord= json.getString("result");
                    Log.d("Msg", json.getString("result"));
                    Toast.makeText(getBaseContext(), resultWord, Toast.LENGTH_SHORT).show();
                    if(resultWord.equals("success")){
                        //Intent login = new Intent(car_detail.this,Offer_Ride.class);
                        //startActivity(login);
                        runOnUiThread(new Runnable() {

                            public void run() {
                                Toast.makeText(getBaseContext(), "car registration successful", Toast.LENGTH_SHORT).show();
                            }
                        });

                        //here you work according to  the usertype and result obtained
                        if(userType==0)//parent
                        {
                            //get the account_id of parent
                            int account_id=Integer.parseInt(json.getString("account_id"));
                            //now send a request to parent
//                            startActivity(new Intent(MainActivity.this, ParentHomeActivity.class));
                        }
                        else if (userType==1)//child
                        {
                            startActivity(new Intent(MainActivity.this, ChildHomeActivity.class));
                        }
                        else if(userType==2)//merchant
                        {
//                            startActivity(new Intent(MainActivity.this, MerchantHomeActivity.class));
                        }
                        finish();
                    }
                    else{
                        runOnUiThread(new Runnable() {

                            public void run() {

                                Toast.makeText(getApplicationContext(), "car registration unsuccessful", Toast.LENGTH_SHORT).show();
                            }
                        });
                    }
                } catch (Exception e) {
                    // TODO Auto-generated catch block
                    e.printStackTrace();
                }


*/
                //generated
                //userType,username,password
                //now send a request









/*
                if(usernametextview.getText().toString().equals("prakash")&&passwordtextview.getText().toString().equals("prk")){


                    ((MyApplication)MainActivity.this.getApplication()).seturlServer(ipAddressServer.getText().toString());

                    */
/*Toast.makeText(getApplicationContext(),"url is="+ Config.DATA_SEND_URL,
                            Toast.LENGTH_LONG).show();*//*


                    startActivity(new Intent(MainActivity.this, ParentHomeActivity.class));

                }
                else{
                    Toast.makeText(getApplicationContext(), "Incorrect Password. Please try again.",
                            Toast.LENGTH_LONG).show();
                }
*/
            }
        });
    }


    private class LoginThroughServerReturnMerchant extends AsyncTask<List<NameValuePair>, Void, Merchant> {
        protected Merchant doInBackground(List<NameValuePair> ... paramsList) {
            Merchant merchantWalletAccountDetail=null;
            Log.d("Msg", "at merch exec");
            for(List<NameValuePair>  params:paramsList) {
                JSONObject json = jsonParser.makeHttpRequest(Config.URL_MERCHANT_LOGIN, "GET", params);
                String resultWord = null;
                try{
                    resultWord= json.getString("result");
                    Log.d("Msg", json.getString("result"));
                    if(resultWord.equals("success")){
                        //populate the child and wallet details
                        merchantWalletAccountDetail=new Merchant();
                        merchantWalletAccountDetail.setAmount((Integer.parseInt(json.getString("amount"))));
                        merchantWalletAccountDetail.setMerchantIDPhoto(((json.getString("merchant_id"))));
                        merchantWalletAccountDetail.setMerchantName(((json.getString("merchant_name"))));
                        merchantWalletAccountDetail.setCategory(((json.getString("category"))));
                        /*merchantWalletAccountDetail.setPaymentAccount(((json.getString("payment_account"))));
                        merchantWalletAccountDetail.setPaymentGateway(((json.getString("payment_gateway"))));*/
                        //finish();
                    }
                    else{
                        //returned no values
                    }
                }
                catch(Exception e){
                    e.getMessage();
                }
            }
            return merchantWalletAccountDetail;
        }
        protected void onPostExecute(Merchant merchantWalletAccountDetail) {
            if(merchantWalletAccountDetail==null){
                //no values returned
            }
            else{
                //go to the merchant home screen
                Intent merchantHomeActivityIntent= new Intent(getApplicationContext(), MerchantHomeActivity.class);
                merchantHomeActivityIntent.putExtra("merchantWalletAccountDetail",merchantWalletAccountDetail);
                startActivity(merchantHomeActivityIntent);
            }
        }
    }

    private class LoginThroughServerReturnChild extends AsyncTask<List<NameValuePair>, Void, ChildWallet> {
        protected ChildWallet doInBackground(List<NameValuePair> ... paramsList) {
            ChildWallet childWalletAccountDetails=null;

            Log.d("Msg", "at child exec");

            for(List<NameValuePair>  params:paramsList) {
                //send request with response as a json object

                JSONObject json = jsonParser.makeHttpRequest(Config.URL_USER_LOGIN, "GET", params);
                String resultWord = null;

                try{

                    resultWord= json.getString("result");
                    Log.d("Msg", json.getString("result"));

                    if(resultWord.equals("success")){
                        //populate the child and wallet details
                        childWalletAccountDetails=new ChildWallet();
                        childWalletAccountDetails.setChild_wallet_id((Integer.parseInt(json.getString("child_wallet_id"))));
                        childWalletAccountDetails.setChild_name(((json.getString("child_name"))));
                        childWalletAccountDetails.setWallet_limit((Integer.parseInt(json.getString("wallet_limit"))));
                        childWalletAccountDetails.setRadius((Integer.parseInt(json.getString("radius"))));
                        childWalletAccountDetails.setLat((Double.parseDouble(json.getString("lat"))));
                        childWalletAccountDetails.setLon((Double.parseDouble(json.getString("lon"))));
                        childWalletAccountDetails.setAmount((Integer.parseInt(json.getString("amount"))));




                        //finish();
                    }
                    else{
                        //returned no values
                    }

                }
                catch(Exception e){
                    e.printStackTrace();
                }
            }
            return childWalletAccountDetails;

        }

        protected void onPostExecute(ChildWallet childWalletAccountDetails) {
            //make intent
            if(childWalletAccountDetails==null){
                //no value returned
            }
            else
            {

                //as this is a call for childwallet details
                //only page for child wallet should be started
                //that is child home screen
                Intent childHomeActivityIntent = new Intent(getApplicationContext(), ChildHomeActivity.class);
                childHomeActivityIntent.putExtra("childWalletDetails",childWalletAccountDetails);
                startActivity(childHomeActivityIntent);
            }


        }
    }



    private class LoginThroughServerReturnAccount extends AsyncTask<List<NameValuePair>, Void, Account> {

        protected Account doInBackground(List<NameValuePair> ... paramsList) {

            Account userAccount=null;

            //this loop should only run once
            for(List<NameValuePair>  params:paramsList){
                //send request with response as a json object

                Log.d("Params",params.toString());

                JSONObject json = jsonParser.makeHttpRequest(Config.URL_USER_LOGIN, "GET", params);
                String resultWord=null;

                try{
                    resultWord= json.getString("result");
                    Log.d("Msg", json.getString("result"));

                    if(resultWord.equals("success")){
                        //populate the Account holder details
                        userAccount=new Account();
                        userAccount.setAccount_balance((Integer.parseInt(json.getString("account_balance"))));
                        userAccount.setAccount_id((Integer.parseInt(json.getString("account_id"))));
                        userAccount.setAccount_name((json.getString("account_name")));

                        //also populate the wallet ids that this account holder holds
                        JSONArray jsonWalletArr = json.getJSONArray("wallets");
                        walletArrayList=new ArrayList<String>();
                        for(int i=0;i<jsonWalletArr.length();i++){
                            JSONObject childJSONWalletObject = jsonWalletArr.getJSONObject(i);
                            walletArrayList.add(childJSONWalletObject.getString("walletid"));
                        }

                        //finish();
                    }
                    else{
                        //returned no values



                    }

                }
                catch(Exception e){
                    e.printStackTrace();
                }


            }


        return userAccount;
        }


        protected void onPostExecute(Account userAccountDetails) {

            //here, we check whether user account data has been generated
            if(userAccountDetails==null){
                //some error resolving techniques
            }
            else{

                //as this is a call for account details
                //only page for user accounts should be started
                //that is parent home screen
                Intent parentHomeActivityIntent = new Intent(getApplicationContext(), ParentHomeActivity.class);
                Log.d("useraccountname",userAccountDetails.getAccount_name());
                Log.d("account_balance",Integer.toString(userAccountDetails.getAccount_balance()));
                Log.d("account_name",Integer.toString(userAccountDetails.getAccount_id()));
                parentHomeActivityIntent.putExtra("userAccountDetails",userAccountDetails);
                parentHomeActivityIntent.putExtra("walletIDsUnderThisAccount",walletArrayList);
                startActivity(parentHomeActivityIntent);
            }
        }

    }
}
