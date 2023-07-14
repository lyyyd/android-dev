package test


// 隐士的 : Any?
// KT做不大，但是可以借助Java来做
class Student : JavaHelp() {

    override fun close() {
        super.close()

        println("KT 我被回收了");
    }


}