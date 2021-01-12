public class Main {
    public static void main(String[] args){
        User user = new User("小北",1);

        IFactory sqlFactory = new SqlServerFactory();

        IUser iu = sqlFactory.createUser();

        iu.Insert(user);

        iu.getUser(1);

        IFactory accFactory = new AccessFactory();

        Department department = new Department("cs",1);

        IDepartment id = accFactory.createDepartment();

        id.Insert(department);

        id.getDepartment("cs");
    }
}
