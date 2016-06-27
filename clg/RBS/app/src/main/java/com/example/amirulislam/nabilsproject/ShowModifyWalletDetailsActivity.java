package com.example.amirulislam.nabilsproject;

import android.content.Intent;
import android.os.AsyncTask;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ExpandableListView;
import android.widget.TextView;

import org.apache.http.NameValuePair;
import org.apache.http.message.BasicNameValuePair;
import org.json.JSONObject;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class ShowModifyWalletDetailsActivity extends AppCompatActivity {


    //the jsonparser
    com.example.amirulislam.nabilsproject.JSONParser jsonParser=new com.example.amirulislam.nabilsproject.JSONParser();


    Account userAccountDetails=null;
    ChildWallet childWalletDetails=null;
    TextView accountBalanceTextView;
    EditText walletAmountTextView;
    EditText areaTextView;
    EditText dailyLimitTextView;
    Button modifyWalletButton;
    Button Trans;
    Button modifyDistanceButton;




    ExpandableListAdapte listAdapter;
    ExpandableListView expListView;
    List<String> listDataHeader;
    HashMap<String, List<String>> listDataChild;




    //this list will be sent back to the next intent(parent homepage)
    ArrayList<String> walletList=null;

    int prev_account_balance=0;
    int new_account_balance=0;
    int prev_wallet_balance=0;
    int new_wallet_balance=0;




    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_show_modify_wallet_details);
        accountBalanceTextView=(TextView)findViewById(R.id.accountBalanceInModifyScreen);
        walletAmountTextView=(EditText)findViewById(R.id.walletbalancetextbox);
        areaTextView=(EditText)findViewById(R.id.areatextbox);
        dailyLimitTextView=(EditText) findViewById(R.id.dailylimittextbox);
        modifyWalletButton=(Button)findViewById(R.id.modifywalletbutton);
        modifyDistanceButton=(Button)findViewById(R.id.distancebutton);
       Trans=(Button)findViewById(R.id.trans);


        populateList();




        getDetailsFromPreviousIntent();
        accountBalanceTextView.setText("" + userAccountDetails.getAccount_balance());
        walletAmountTextView.setText(""+childWalletDetails.getAmount());
        areaTextView.setText(""+childWalletDetails.getRadius());
        dailyLimitTextView.setText(""+childWalletDetails.getWallet_limit());


        Trans.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v)
            {
                Intent TransActivityIntent = new Intent(getApplicationContext(),Transactions.class);
                startActivity(TransActivityIntent);
            }
        });
        modifyWalletButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                //here we modify the wallet and the account table

                new_wallet_balance=Integer.parseInt(walletAmountTextView.getText().toString());
                new_account_balance=prev_account_balance-(new_wallet_balance-prev_wallet_balance);


                List<NameValuePair> params = new ArrayList<NameValuePair>();

                //for account holder (parent)
                params.add(new BasicNameValuePair("account_id", Integer.toString(userAccountDetails.getAccount_id())));
                params.add(new BasicNameValuePair("account_balance", Integer.toString(new_account_balance)));

                //for wallet

                params.add(new BasicNameValuePair("child_wallet_id", Integer.toString(childWalletDetails.getChild_wallet_id())));
                params.add(new BasicNameValuePair("amount", Integer.toString(new_wallet_balance)));
                params.add(new BasicNameValuePair("radius", (areaTextView.getText().toString())));
                params.add(new BasicNameValuePair("limit", (dailyLimitTextView.getText().toString())));

                UpdateWalletAccount updateWalletAsyncAct=new UpdateWalletAccount();
                updateWalletAsyncAct.execute(params);

            }
        });


        modifyDistanceButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                Intent mapActivityIntent = new Intent(getApplicationContext(), MapsActivity.class);
                mapActivityIntent.putExtra("ShowModifyWalletDetails",childWalletDetails);
                mapActivityIntent.putExtra("walletIDsUnderThisAccount",walletList);
                mapActivityIntent.putExtra("userAccountDetails",userAccountDetails);
                startActivity(mapActivityIntent);
            }
        });


    }

    public void populateList(){

        expListView = (ExpandableListView)findViewById(R.id.left_drawer2);

        // preparing list data
        prepareListData();

        listAdapter = new ExpandableListAdapte(this, listDataHeader, listDataChild);

        // setting list adapter
        expListView.setAdapter(listAdapter);


    }

    /*
 * Preparing the list data
 */
    private void prepareListData() {
        listDataHeader = new ArrayList<String>();
        listDataChild = new HashMap<String, List<String>>();

        // Adding child data
        listDataHeader.add("Food Zone");
        listDataHeader.add("Entertainment");
        listDataHeader.add("Electrical");

        // Adding child data
        List<String> top250 = new ArrayList<String>();
        top250.add("Barista");
        top250.add("KFC");
        top250.add("Dominos");


        List<String> nowShowing = new ArrayList<String>();
        nowShowing.add("PVR");
        nowShowing.add("Inox");


        List<String> comingSoon = new ArrayList<String>();
        comingSoon.add("Reliance");
        comingSoon.add("EZone");
        comingSoon.add("GameZone");

        listDataChild.put(listDataHeader.get(0), top250); // Header, Child data
        listDataChild.put(listDataHeader.get(1), nowShowing);
        listDataChild.put(listDataHeader.get(2), comingSoon);
    }


    protected void getDetailsFromPreviousIntent() {
        //get data from what has been passed
        Intent parentHomeIntent = getIntent();
        userAccountDetails = (Account) parentHomeIntent.getSerializableExtra("userAccountDetails");
        childWalletDetails=(ChildWallet) parentHomeIntent.getSerializableExtra("ShowModifyWalletDetails");
        prev_account_balance=userAccountDetails.getAccount_balance();
        prev_wallet_balance=childWalletDetails.getAmount();

        ArrayList<String> walletIDsList=getIntent().getStringArrayListExtra("walletIDsUnderThisAccount");
        walletList=walletIDsList;

    }








    private class UpdateWalletAccount extends AsyncTask<List<NameValuePair>, Void, Boolean> {
        protected Boolean doInBackground(List<NameValuePair> ... paramsList) {
            boolean updateResult=false;

            for(List<NameValuePair>  params:paramsList) {
                JSONObject json = jsonParser.makeHttpRequest(Config.URL_UPDATE_WALLET_ACCOUNT, "GET", params);
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
                userAccountDetails.setAccount_balance(new_account_balance);
                //now set the userclass so that it can be sent to the next intent
                Log.d("hello","pass");
                Intent parentHomeActivityIntent = new Intent(getApplicationContext(), ParentHomeActivity.class);
                parentHomeActivityIntent.putExtra("userAccountDetails",userAccountDetails);
                parentHomeActivityIntent.putExtra("walletIDsUnderThisAccount",walletList);
                startActivity(parentHomeActivityIntent);

            }
        }







}
}