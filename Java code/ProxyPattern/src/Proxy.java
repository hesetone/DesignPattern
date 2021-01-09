public class Proxy extends Subject{
    public RealSubject realSubject;

    @Override
    public void request(){
        if(realSubject == null){
            realSubject = new RealSubject();
        }
        realSubject.request();
    }
}
