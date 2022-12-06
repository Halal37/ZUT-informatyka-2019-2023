package ai2.lab10.CRUD;

import javax.persistence.*;
import java.util.Date;

@Entity
public class Weather {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;
    private Date date;
    private double temperature;

    @ManyToOne(cascade = CascadeType.ALL)
    private City cityId;

    public Long getId() {
        return id;
    }

    public Date getDate() {
        return date;
    }

    public double getTemperature() {
        return temperature;
    }

    public City getCityId() {
        return cityId;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public void setDate(Date date) {
        this.date = date;
    }

    public void setTemperature(double temperature) {
        this.temperature = temperature;
    }

    public void setCityId(City cityId) {
        this.cityId = cityId;
    }
}