package PrototypePattern;

public abstract class Prototype {
    private String mID;

    public Prototype(String id){
        mID = id;
    }

    public String getID() {
        return mID;
    }

    public abstract Prototype Clone();
}
