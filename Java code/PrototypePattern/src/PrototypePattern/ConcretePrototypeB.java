package PrototypePattern;

public class ConcretePrototypeB extends Prototype implements Cloneable{
    public ConcretePrototypeB(String id){
        super(id);
    }

    @Override
    public Prototype Clone(){
        Prototype prototype = null;
        try{
            prototype = (Prototype) clone();
        }catch(CloneNotSupportedException e){
            e.printStackTrace();
        }
        return prototype;
    }
}
