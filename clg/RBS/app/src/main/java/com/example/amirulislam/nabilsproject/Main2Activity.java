package com.example.amirulislam.nabilsproject;

import android.os.AsyncTask;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.TextView;
import android.widget.TimePicker;
import android.widget.Toast;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.net.HttpURLConnection;
import java.net.URL;
import java.util.Calendar;

import javax.net.ssl.HttpsURLConnection;

public class Main2Activity extends AppCompatActivity {


    private TimePicker timePicker1;
    private TextView time;
    private Calendar calendar;
    private String format = "";


    static String DataToBeSent=null;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);

        timePicker1 = (TimePicker) findViewById(R.id.timePicker1);
        //time = (TextView) findViewById(R.id.textView1);
        calendar = Calendar.getInstance();

        int hour = calendar.get(Calendar.HOUR_OF_DAY);
        int min = calendar.get(Calendar.MINUTE);
        //showTime(hour, min);
    }

    public void setTime(View view) {
        int hour = timePicker1.getCurrentHour();
        int min = timePicker1.getCurrentMinute();


        Toast.makeText(getApplicationContext(), hour+"  "+min,
                Toast.LENGTH_LONG).show();


        ((MyApplication)Main2Activity.this.getApplication()).setHour(Integer.toString(hour));
        ((MyApplication)Main2Activity.this.getApplication()).setMinute(Integer.toString(min));
        //now try sending the data
        DataToBeSent=null;
        DataToBeSent=((MyApplication) this.getApplication()).getQuantity()+"$"+((MyApplication) this.getApplication()).getHour()+"$";
        DataToBeSent=DataToBeSent+((MyApplication) this.getApplication()).getMinute();

        new SendData().execute();






  //      showTime(hour, min);
    }



    private class SendData extends AsyncTask<Void,Void,String>{



        URL url;
        String response = "";


        @Override
        protected void onPreExecute() {
            super.onPreExecute();
            try{
                url = new URL(Config.DATA_SEND_URL );
            }
            catch (Exception e){
                e.getMessage();
            }
            Toast.makeText(getApplicationContext(),url.toString(),Toast.LENGTH_SHORT).show();


        }

        protected String doInBackground(Void... params) {




            try{


                HttpURLConnection conn = (HttpURLConnection) url.openConnection();
                conn.setReadTimeout(15000);
                conn.setConnectTimeout(15000);
                conn.setRequestMethod("POST");
                conn.setDoInput(true);
                conn.setDoOutput(true);
                //Toast.makeText(getApplicationContext(),"going to upload",Toast.LENGTH_SHORT).show();
                OutputStream os = conn.getOutputStream();
                BufferedWriter writer = new BufferedWriter(
                        new OutputStreamWriter(os, "UTF-8"));

                //formulate data to be written
                /*String dataToBeSent=((MyApplication) this.getApplication()).getQuantity()+"$"+((MyApplication) this.getApplication()).getHour()+"$";
                dataToBeSent=dataToBeSent+((MyApplication) this.getApplication()).getMinute();*/



                writer.write(DataToBeSent);
                writer.flush();
                writer.close();
                os.close();

                int responseCode=conn.getResponseCode();

                if (responseCode == HttpsURLConnection.HTTP_OK) {
/*
                    Toast.makeText(getApplicationContext(), "Data Sent",
                            Toast.LENGTH_LONG).show();
*/
                    String line;
                    BufferedReader br=new BufferedReader(new InputStreamReader(conn.getInputStream()));
                    while ((line=br.readLine()) != null) {
                        response+=line;
                    }



/*
                    Toast.makeText(getApplicationContext(), response,
                            Toast.LENGTH_LONG).show();
*/
                }
                else {
                    response="";
/*
                    Toast.makeText(getApplicationContext(), "Data not Sent",
                            Toast.LENGTH_LONG).show();
*/

                }



            }
            catch(Exception e){
                e.printStackTrace();
            }

            return response;


        }
    }


    /*public void showTime(int hour, int min) {
        if (hour == 0) {
            hour += 12;
            format = "AM";
        }
        else if (hour == 12) {
            format = "PM";
        } else if (hour > 12) {
            hour -= 12;
            format = "PM";
        } else {
            format = "AM";
        }
        time.setText(new StringBuilder().append(hour).append(" : ").append(min)
                .append(" ").append(format));
    }

*/
}