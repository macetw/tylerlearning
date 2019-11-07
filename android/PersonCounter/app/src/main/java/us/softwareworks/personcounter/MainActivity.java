package us.softwareworks.personcounter;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    Button clickButton;
    Button resetButton;
    TextView valueTextView;

    /*
     Created while working tutorial at:
        https://www.youtube.com/watch?v=0wrJA3mAcSo
    */
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        clickButton = (Button)findViewById(R.id.clickButton);
        resetButton = (Button)findViewById(R.id.resetButton);
        valueTextView = (TextView)findViewById(R.id.valueTextView);

        clickButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String countVal = valueTextView.getText().toString();
                int countInt = Integer.parseInt(countVal);
                countInt++;
                valueTextView.setText(String.valueOf(countInt));
            }
        });
        resetButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                valueTextView.setText("0");
            }
        });
    }
}
