package com.example.amirulislam.nabilsproject;

import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

public class Main22QuantityActivity extends AppCompatActivity {


    EditText quantitytextview;
    Button saveQuantityButton;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main22_quantity);
        quantitytextview=(EditText)findViewById(R.id.editTextQuantity);
        saveQuantityButton=(Button)findViewById(R.id.quantitysavebutton);




        saveQuantityButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                ((MyApplication)Main22QuantityActivity.this.getApplication()).setQuantity(quantitytextview.getText().toString());


                startActivity(new Intent(Main22QuantityActivity.this, Main2Activity.class));



            }
        });








    }
}
