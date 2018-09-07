package me.study.msgdigest.digest;

/**
 * Created by admin on 2018/9/7.
 */

public class MD5Helper {



    static {

        System.loadLibrary("digest");

    }


    public native static String getFileMd5(String filePath);





}
