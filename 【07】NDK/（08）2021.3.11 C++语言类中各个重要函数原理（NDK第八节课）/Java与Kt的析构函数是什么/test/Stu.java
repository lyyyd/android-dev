package test;

// 默认隐士  extends Object
public class Stu {

    // 并不是这样说的，Java调用了finalize函数，代表这个类可能被回收了（回收的前兆）
    // 此类加入到queue队列中，等待虚拟机来处理（只有虚拟机处理回收了，才叫回收）
    @Override
    protected void finalize() throws Throwable {
        super.finalize();

        System.out.println("Java 我被回收了");
    }
}
