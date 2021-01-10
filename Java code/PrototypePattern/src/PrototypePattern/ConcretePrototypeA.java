package PrototypePattern;

public class ConcretePrototypeA extends Prototype implements Cloneable{
    /*
    * @author wsh-nie
    * 此类实现了Cloneable接口，以指示Object的clone()方法可以合法地对该类实例进行按字段复制
    * 按照惯例，实现此接口的类应该使用公共方法重写Object的clone()方法，Object的clone()方法是一个受保护的方法
    * */

    public ConcretePrototypeA(String id) {
        super(id);
    }

    @Override
    public Prototype Clone(){
        Prototype prototype = null;
        try{
            prototype = (Prototype) clone();
        }catch(CloneNotSupportedException e){
            /*
            * 如果在没有实现Cloneable接口的实例上调用Object的clone()方法，则会导致抛出CloneNotSupportedException
            * */
            e.printStackTrace();
        }
        return prototype;
    }
}
