package com.example.amirulislam.nabilsproject;

import android.content.Intent;
import android.os.AsyncTask;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.View;
import android.widget.AdapterView;
import android.widget.AdapterView.OnItemClickListener;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;

import org.apache.http.NameValuePair;
import org.apache.http.message.BasicNameValuePair;
import org.json.JSONObject;

import java.util.ArrayList;
import java.util.List;

public class ParentHomeActivity extends AppCompatActivity {
    com.example.amirulislam.nabilsproject.JSONParser jsonParser=new com.example.amirulislam.nabilsproject.JSONParser();

    ListView walletListView;

    TextView accountBalanceTextView;
    ArrayList<String> walletList=null;
    Account userAccountDetails=null;
    int wallet_id=0;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_parent_home);
        walletListView=(ListView)findViewById(R.id.walletListView);
        accountBalanceTextView=(TextView)findViewById(R.id.accountBalance);

        getDetailsFromPreviousIntent();
        accountBalanceTextView.setText("" + userAccountDetails.getAccount_balance());
        generateWallets();

        //now the listener for the list of wallets
        walletListView.setOnItemClickListener(new OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position,
                                    long id) {

                String item = ((TextView)view).getText().toString();
                Toast.makeText(getBaseContext(), item, Toast.LENGTH_SHORT).show();
                //now make a query to the server with the wallet id
                //populate parameters for request
                List<NameValuePair> params = new ArrayList<NameValuePair>();
                params.add(new BasicNameValuePair("child_wallet_id", item));
                wallet_id=Integer.parseInt(item);

                ParentGetSingleWalletDetail getSingleWalletDetailAsyncActivity=new ParentGetSingleWalletDetail();
                getSingleWalletDetailAsyncActivity.execute(params);



                //here start a new intent while passing the selected wallet
            }
        });
    }

    protected void getDetailsFromPreviousIntent(){
        //get data from what has been passed
        Intent parentHomeIntent=getIntent();
        userAccountDetails=(Account)parentHomeIntent.getSerializableExtra("userAccountDetails");


        ArrayList<String> walletIDsList=getIntent().getStringArrayListExtra("walletIDsUnderThisAccount");
        walletList=walletIDsList;
    }
    protected void generateWallets(){
        //populate data into arraylist
        String[] walletArray = {"Wallet1","Wallet2","Wallet3","Wallet4"};

        //walletList=new ArrayList<String>(Arrays.asList(walletArray));


        //alternatively a call to database to get
        //a. account balance
        //b. wallets details






        //getnerate the view
        ArrayAdapter adapter = new ArrayAdapter<String>(this, R.layout.activity_listview, walletList);

        ListView listView = (ListView) findViewById(R.id.walletListView);
        listView.setAdapter(adapter);
    }




    private class ParentGetSingleWalletDetail extends AsyncTask<List<NameValuePair>, Void, ChildWallet> {
        protected ChildWallet doInBackground(List<NameValuePair> ... paramsList) {
            ChildWallet childWalletAccountDetails=null;

            for(List<NameValuePair>  params:paramsList) {
                //send request with response as a json object

                JSONObject json = jsonParser.makeHttpRequest(Config.WALLET_DETAILS_FOR_PARENT, "GET", params);
                String resultWord = null;

                try{

                    resultWord= json.getString("result");
                    Log.d("Msg", json.getString("result"));

                    if(resultWord.equals("success")){
                        //populate the child and wallet details
                        childWalletAccountDetails=new ChildWallet();
                        //childWalletAccountDetails.setUsername(((json.getString("username"))));

                        //for below use global var
                        //childWalletAccountDetails.setChild_wallet_id((Integer.parseInt(json.getString("child_wallet_id"))));
                        childWalletAccountDetails.setChild_wallet_id(wallet_id);

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
                    return childWalletAccountDetails;
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
            else{


                Log.d("msg","after getting specific child wallet details");
                Log.d("amount",Integer.toString(childWalletAccountDetails.getAmount()));
                Log.d("lat", Double.toString(childWalletAccountDetails.getLat()));
                Log.d("limit",Integer.toString(childWalletAccountDetails.getWallet_limit()));

                //as this is a call for childwallet details
                //only page for child wallet should be started
                //that is child home screen
                Intent ShowModifyWalletDetailsActivityIntent = new Intent(getApplicationContext(), ShowModifyWalletDetailsActivity.class);
                ShowModifyWalletDetailsActivityIntent.putExtra("ShowModifyWalletDetails",childWalletAccountDetails);
                //also put account details
                ShowModifyWalletDetailsActivityIntent.putExtra("userAccountDetails",userAccountDetails);
                //also send the list of wallets as they will be used later
                ShowModifyWalletDetailsActivityIntent.putExtra("walletIDsUnderThisAccount",walletList);


                startActivity(ShowModifyWalletDetailsActivityIntent);


            }
        }
    }




}
