package test;

public class Main {

    public static void main(String[] aaa) {

        // ====== Java 回收

        Stu stu = new Stu();

        stu = null;
        System.gc();; // gc机制来扫描吧，gc一过来发现，stu还有指向，扫你妹啊


        // ===== KT 回收

        Student student = new Student();
        student = null;
        System.gc();;
    }

}
