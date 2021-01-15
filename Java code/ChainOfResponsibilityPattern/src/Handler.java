
public abstract class Handler {
    protected Handler successor;

    public void setSuccessor(Handler successor){
        /*
        * @author wsh-nie
        * 设置继任者
        * */
        this.successor = successor;
    }

    public abstract void handlerRequest(int request);
}
