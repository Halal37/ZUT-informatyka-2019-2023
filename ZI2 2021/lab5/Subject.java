import javax.persistence.*;
import java.util.List;

@Entity
public class Subject {
    @Id
    @GeneratedValue
    private Long id;
    private String name;
    @ManyToOne(cascade = CascadeType.ALL)
    private Teacher teachers;

    public Teacher getTeachers() {
        return teachers;
    }

    public void setTeachers(Teacher teachers) {
        this.teachers = teachers;
    }

    public List<Class> getClasss() {
        return classs;
    }

    public void setClasss(List<Class> classs) {
        this.classs = classs;
    }

    @ManyToMany(cascade = CascadeType.ALL)
    private List<Class> classs;
    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
}
