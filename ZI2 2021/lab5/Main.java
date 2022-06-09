import javax.persistence.EntityManager;
import javax.persistence.Persistence;
import javax.persistence.Query;
import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {

   EntityManager em = Persistence.createEntityManagerFactory("labs").createEntityManager();
    Class k = new Class();
   k.setName("Ib");
   k.setYear(1);
   Class k3 = new Class();
   k3.setName("Vc");
   k3.setYear(5);
   Class k2 = new Class();
   k2.setName("IVb");
   k2.setYear(4);


   Student u1=new Student();
   u1.setFirstname("Antoni");
   u1.setLastname("Pepperoni");
   u1.setClasss(k);

   Student u2= new Student();
   u2.setFirstname("Anna");
   u2.setLastname("Dluga");
   u2.setClasss(k);

   Student u3= new Student();
   u3.setFirstname("Pawel");
   u3.setLastname("Srogi");
   u3.setClasss(k);

   Student u4= new Student();
   u4.setFirstname("Anna");
   u4.setLastname("Koska");
   u4.setClasss(k);

   Student u5= new Student();
   u5.setFirstname("Janina");
   u5.setLastname("Barka");
   u5.setClasss(k);
       Student u6=new Student();
       u6.setFirstname("Damian");
       u6.setLastname("Rys");
       u6.setClasss(k2);

       Student u7= new Student();
       u7.setFirstname("Kajetan");
       u7.setLastname("Kubik");
       u7.setClasss(k2);

       Student u8= new Student();
       u8.setFirstname("Piotr");
       u8.setLastname("Koronny");
       u8.setClasss(k2);

       Student u9= new Student();
       u9.setFirstname("Agata");
       u9.setLastname("Koral");
       u9.setClasss(k2);

       Student u10= new Student();
       u10.setFirstname("Krzysztof");
       u10.setLastname("Radziszewski");
       u10.setClasss(k2);

       Student u11=new Student();
       u11.setFirstname("Kajetan");
       u11.setLastname("Krason");
       u11.setClasss(k3);

       Student u12= new Student();
       u12.setFirstname("Piotr");
       u12.setLastname("Cholewa");
       u12.setClasss(k3);

       Student u13= new Student();
       u13.setFirstname("Paulina");
       u13.setLastname("Samba");
       u13.setClasss(k3);

       Student u14= new Student();
       u14.setFirstname("Anna");
       u14.setLastname("Czerwionka");
       u14.setClasss(k3);

       Student u15= new Student();
       u15.setFirstname("Wojciech");
       u15.setLastname("Kopyto");
       u15.setClasss(k3);

   k.setStudents(new ArrayList<>());
   k.getStudents().add(u1);
   k.getStudents().add(u2);
   k.getStudents().add(u3);
   k.getStudents().add(u4);
   k.getStudents().add(u5);

   k2.setStudents(new ArrayList<>());
   k2.getStudents().add(u6);
   k2.getStudents().add(u7);
   k2.getStudents().add(u8);
   k2.getStudents().add(u9);
   k2.getStudents().add(u10);

   k3.setStudents(new ArrayList<>());
   k3.getStudents().add(u11);
   k3.getStudents().add(u12);
   k3.getStudents().add(u13);
   k3.getStudents().add(u14);
   k3.getStudents().add(u15);

       Subject s1=new Subject();
       s1.setName("Biologia");
       s1.setClasss(new ArrayList<>());
       s1.getClasss().add(k);
       s1.getClasss().add(k2);

       Subject s2=new Subject();
       s2.setName("Chemia");
       s2.setClasss(new ArrayList<>());
       s2.getClasss().add(k);
       s2.getClasss().add(k2);

       Subject s3=new Subject();
       s3.setName("Matematyka");
       s3.setClasss(new ArrayList<>());
       s3.getClasss().add(k);
       s3.getClasss().add(k2);

       Subject s4=new Subject();
       s4.setName("J.Angielski");
       s4.setClasss(new ArrayList<>());
       s4.getClasss().add(k);
       s4.getClasss().add(k2);

       Subject s5=new Subject();
       s5.setName("J.Polski");
       s5.setClasss(new ArrayList<>());
       s5.getClasss().add(k3);
       Subject s6=new Subject();
       s6.setName("Historia");
       s6.setClasss(new ArrayList<>());
       s6.getClasss().add(k3);
       Subject s7=new Subject();
       s7.setName("Wos");
       s7.setClasss(new ArrayList<>());
       s7.getClasss().add(k3);
       Subject s8=new Subject();
       s8.setName("J.Niemiecki");
       s8.setClasss(new ArrayList<>());
       s8.getClasss().add(k3);

       Teacher t1=new Teacher();
       t1.setFirstname("Jakub");
       t1.setLastname("Grabowski");
       t1.setClasss(k);
       t1.setSubjects(new ArrayList<>());
       t1.getSubjects().add(s1);
       t1.getSubjects().add(s2);
       k.setTeachers(t1);
       s1.setTeachers(t1);
       s2.setTeachers(t1);

       Teacher t2=new Teacher();
       t2.setFirstname("Antoni");
       t2.setLastname("Munk");
       t2.setClasss(k2);
       t2.setSubjects(new ArrayList<>());
       t2.getSubjects().add(s3);
       t2.getSubjects().add(s4);
       k2.setTeachers(t2);
       s3.setTeachers(t2);
       s4.setTeachers(t2);

       Teacher t3=new Teacher();
       t3.setFirstname("Aleksandra");
       t3.setLastname("Nicien");
       t3.setClasss(k3);
       t3.setSubjects(new ArrayList<>());
       t3.getSubjects().add(s6);
       t3.getSubjects().add(s7);
       t3.getSubjects().add(s5);
       t3.getSubjects().add(s8);
       k3.setTeachers(t3);
       s5.setTeachers(t3);
       s6.setTeachers(t3);
       s7.setTeachers(t3);
       s8.setTeachers(t3);

       k.setSubjects(new ArrayList<>());
       k.getSubjects().add(s1);
       k.getSubjects().add(s2);
       k.getSubjects().add(s3);
       k.getSubjects().add(s4);

       k2.setSubjects(new ArrayList<>());
       k2.getSubjects().add(s1);
       k2.getSubjects().add(s2);
       k2.getSubjects().add(s3);
       k2.getSubjects().add(s4);

       k3.setSubjects(new ArrayList<>());
       k3.getSubjects().add(s5);
       k3.getSubjects().add(s6);
       k3.getSubjects().add(s7);
       k3.getSubjects().add(s8);

   em.getTransaction().begin();
   em.persist(k);
   em.persist(k2);
   em.persist(k3);
   em.getTransaction().commit();


        Query query=em.createQuery("SELECT p FROM Student p where p.lastname='Srogi' ");
        List<Student> lis=query.getResultList();
        for(Student u: lis){
            Class s= u.getClasss();
            List<Subject> el=s.getSubjects();
            for(Subject i: el){
                System.out.println(i.getName());
            }
        }
        Query query2=em.createQuery("SELECT p FROM Teacher p where p.lastname='Munk' ");
        List<Teacher> lis2=query2.getResultList();
        for(Teacher u: lis2){
            List<Subject> el2=u.getSubjects();
            for(Subject i: el2){
                List<Class> kla=i.getClasss();
                for(Class j:kla){
                    List<Student> stu=j.getStudents();
                    for(Student op:stu)
                    System.out.println(op.getFirstname()+ " "+op.getLastname());
                }
            }
        }


    }
}
