package ai2.lab10.CRUD;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class CityService {
    private final CityCrudRepository repository;

    @Autowired
    public CityService(CityCrudRepository repository){
        this.repository = repository;
    }

    public Iterable<City> getCities(){
        return repository.findAll();
    }
}
