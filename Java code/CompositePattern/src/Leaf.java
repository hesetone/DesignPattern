public class Leaf extends Component{
    public Leaf(String name){
        super(name);
    }
    /*
    * @author wsh-nie
    * 叶子节点没有再增加分支和树叶，所以Add和Remove方法实现无意义 ；
    * 但可以消除叶节点和枝节点对象在抽象层次的区别，它们具备完全一致的接口。
    * */

    @Override
    public void add(Component component){
        System.out.println("Cannot add to a leaf");
    }
    @Override
    public void remove(Component component){
        System.out.println("Cannot remove to a leaf");

    }
    @Override
    public void display(int depth){
        StringBuilder stringBuilder = new StringBuilder();
        for(int i=0; i<depth; i++){
            stringBuilder.append("-");
        }
        System.out.println(stringBuilder.append(this.mName).toString());
    }
}
