package ai2.lab10.CRUD;

import org.springframework.data.domain.Page;
import org.springframework.data.domain.Pageable;
import org.springframework.data.repository.CrudRepository;
import org.springframework.data.rest.core.annotation.RepositoryRestResource;
import org.springframework.format.annotation.DateTimeFormat;
import java.util.Date;

@RepositoryRestResource(path="weather")
public interface WeatherCrudRepository extends CrudRepository<Weather, Long> {
    Page<Weather> findByDateGreaterThanEqualAndCityId(@DateTimeFormat(pattern = "yyyy-MM-dd") Date date, City city, Pageable pageable);
}