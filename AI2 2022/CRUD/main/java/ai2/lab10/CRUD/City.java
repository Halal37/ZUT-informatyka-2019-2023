package ai2.lab10.CRUD;

import com.fasterxml.jackson.annotation.JsonIgnoreProperties;

import javax.persistence.*;
import java.util.ArrayList;
import java.util.List;

@Entity
@JsonIgnoreProperties({"cityName", "country", "latitude", "longitude"})
public class City {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;
    private String cityName;
    private String country;
    private double latitude;
    private double longitude;

    @OneToMany(cascade = CascadeType.ALL, mappedBy = "cityId")
    List<Weather> weather = new ArrayList<>();

    public List<Weather> getWeather(){return weather;}

    public Long getId() {
        return id;
    }

    public String getCityName() {
        return cityName;
    }

    public String getCountry() {
        return country;
    }

    public double getLatitude() {
        return latitude;
    }

    public double getLongitude() {
        return longitude;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public void setCityName(String cityName) {
        this.cityName = cityName;
    }

    public void setCountry(String country) {
        this.country = country;
    }

    public void setLatitude(double latitude) {
        this.latitude = latitude;
    }

    public void setLongitude(double longitude) {
        this.longitude = longitude;
    }

    public void setWeather(List<Weather> weather) {
        this.weather = weather;
    }
}