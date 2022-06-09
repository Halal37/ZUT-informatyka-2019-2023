import javax.persistence.*;

@Entity
public class Student {
    @Id
    @GeneratedValue
    private Long id;
    private String firstname;
    private String lastname;
    @ManyToOne(cascade = CascadeType.ALL)
    private Class classs;

    public Class getClasss() {
        return classs;
    }

    public void setClasss(Class classs) {
        this.classs = classs;
    }

    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public String getFirstname() {
        return firstname;
    }

    public void setFirstname(String firstname) {
        this.firstname = firstname;
    }

    public String getLastname() {
        return lastname;
    }

    public void setLastname(String lastname) {
        this.lastname = lastname;
    }
}