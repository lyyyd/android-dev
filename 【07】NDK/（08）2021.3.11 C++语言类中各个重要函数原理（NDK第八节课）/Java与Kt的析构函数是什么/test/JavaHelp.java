package test;

import java.io.Closeable;
import java.io.IOException;

// 隐士 extends Object
public class JavaHelp implements Closeable {


    @Override
    protected void finalize() throws Throwable {
        super.finalize();
        close();
    }

    @Override
    public void close() throws IOException {

    }
}
