public class User {
    private String mName;
    private int mID;

    public User(String name, int id){
        this.mName = name;
        this.mID = id;
    }

    public String getName(){
        return this.mName;
    }

    public int getID(){
        return this.mID;
    }
}
