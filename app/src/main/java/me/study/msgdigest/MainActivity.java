package me.study.msgdigest;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import me.study.msgdigest.digest.MD5Helper;
import me.study.msgdigest.utils.AppUtils;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    private TextView tvHello, tvMd5;
    private Button btnHello, btnMd5;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);


        initView();
        initListener();

        initData();
    }

    private void initView() {
        // Example of a call to a native method
        tvHello = (TextView) findViewById(R.id.tv_hello);
        tvMd5 = (TextView) findViewById(R.id.tv_md5);
        btnHello = (Button) findViewById(R.id.btn_hello);
        btnMd5 = (Button) findViewById(R.id.btn_md5);
    }

    private void initData() {


    }

    private void initListener() {
        btnHello.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                tvHello.setText(stringFromJNI());
            }
        });
        btnMd5.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                String appPath = AppUtils.getAppPath();

                tvMd5.setText(MD5Helper.getFileMd5(appPath));

            }
        });

    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
}
