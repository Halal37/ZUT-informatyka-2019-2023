import javax.persistence.*;
import java.util.List;

@Entity
public class Class {
    @Id
    @GeneratedValue
    private Long id;
    private String name;
    private Integer year;


    @ManyToMany(cascade = CascadeType.ALL,mappedBy="classs")
    private List<Subject> subjects;
    @OneToMany(cascade = CascadeType.ALL,mappedBy="classs")
    private List<Student> students;
    @OneToOne(cascade = CascadeType.ALL)
    private Teacher teachers;

    public List<Subject> getSubjects() {
        return subjects;
    }

    public void setSubjects(List<Subject> subjects) {
        this.subjects = subjects;
    }

    public Teacher getTeachers() {
        return teachers;
    }

    public void setTeachers(Teacher teachers) {
        this.teachers = teachers;
    }

    public List<Student> getStudents() {
        return students;
    }

    public void setStudents(List<Student> students) {
        this.students = students;
    }

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
    public Integer getYear() {
        return year;
    }

    public void setYear(Integer year) {
        this.year = year;
    }
}
