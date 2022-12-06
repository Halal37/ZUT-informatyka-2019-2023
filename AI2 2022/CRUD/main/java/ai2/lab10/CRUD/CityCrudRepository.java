package ai2.lab10.CRUD;
import org.springframework.data.domain.Page;
import org.springframework.data.domain.Pageable;
import org.springframework.data.repository.CrudRepository;
import org.springframework.data.rest.core.annotation.RepositoryRestResource;

import java.util.List;

@RepositoryRestResource(path="city")
public interface CityCrudRepository extends CrudRepository<City, Long>{
    Page<City> findCityByCountry(String country, Pageable pageable);
    List<City> findDistinctCityByCityName(String cityName);
}
