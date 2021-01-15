public class ConcreteHandlerC extends Handler{
    @Override
    public void handlerRequest(int request) {
        if(request < 0 || request >= 20){
            System.out.println(this.getClass().toString() + "处理请求" + request);
        }else if (successor != null){
            successor.handlerRequest(request);
        }
    }
}
