import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;

@Entity
public class Person {
    @Id
    @GeneratedValue(strategy= GenerationType.AUTO)
    private long id;
    private String firstName;
    private String familyName;
    private int age;
    public Long getId(){return id;}
    public void setId(Long id){this.id=id;}
    public String getFirstName(){return firstName;}
    public void setFirstName(String firstName){this.firstName=firstName;}
    public String getFamilyName(){return familyName;}
    public void setFamilyName(String familyName){
        this.familyName=familyName;
    }
    public void setAge(int age) {
        this.age = age;
    }

}

