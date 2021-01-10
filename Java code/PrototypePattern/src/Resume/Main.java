package Resume;

public class Main {
    public static void main(String[] args) {
        Resume a = new Resume("大鸟");
        a.setPersonInfo("男", "29");
        a.setWorkExperience("1998-2000", "XX公司");

        Resume b = (Resume) a.Clone();
        b.setWorkExperience("1998-2006","YY企业");

        Resume c = (Resume) a.Clone();
        c.setWorkExperience("1998-2003","ZZ企业");

        a.display();
        b.display();
        c.display();

    }
}
