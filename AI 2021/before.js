const WeatherApp = class {
    constructor(apiKey, resultsBlockSelector) {
this.apiKey=apiKey;

        this.currentWeather = undefined;
        this.forecast = undefined;
        this.currentWeatherLink = "https://api.openweathermap.org/data/2.5/weather?q={query}&appid={apiKey}&units=metric&lang=pl";
this.forecastLink = "https://api.openweathermap.org/data/2.5/forecast?q={query}&appid={apiKey}&units=metric&lang=pl";
        this.iconLink = "https://openweathermap.org/img/wn/{iconName}@2x.png";
        this.currentWeatherLink = this.currentWeatherLink.replace("{apiKey}", this.apiKey);
        this.forecastLink = this.forecastLink.replace("{apiKey}", this.apiKey);
this.resultsBlock=document.querySelector(resultsBlockSelector);
    }

    getCurrentWeather(query) {
        let url = this.currentWeatherLink.replace("{query}", query);
        let req = new XMLHttpRequest();
        req.open("GET", url, true);
        req.addEventListener("load", () => {
            this.currentWeather = JSON.parse(req.responseText);
            console.log(this.currentWeather);
            this.drawWeather();
        });
        req.send();
    }

    getForecast(query) {
        let url = this.forecastLink.replace("{query}", query);
        fetch(url).then((response) => {
            return response.json();
        }).then((data) => {
            console.log(data);
            this.forecast = data.list;
            this.drawWeather();
        });
    }

    getWeather(query) {
        this.getCurrentWeather(query);
        this.getForecast(query);
//this.resultBlock.innerText=query;
    }

    drawWeather() {
        this.resultsBlock.innerHTML = '';		
if (this.currentWeather) {
	const date = new Date(this.currentWeather.dt * 1000);
	const dateTimeString = `${date.toLocaleDateString("pl-PL")} ${date.toLocaleTimeString("pl-PL")}`;
	            const temperature = this.currentWeather.main.temp;
            const feelsLikeTemperature = this.currentWeather.main.feels_like;
            const iconName = this.currentWeather.weather[0].icon;
            const description = this.currentWeather.weather[0].description;
			            const weatherBlock = this.createWeatherBlock(dateTimeString, temperature, feelsLikeTemperature, iconName, description);
this.resultsBlock.appendChild(weatherBlock);
	 }
	         if (this.forecast && this.forecast.length > 0) {
            for (let i = 0; i < this.forecast.length; i++) {
                let weather = this.forecast[i];
                const date = new Date(weather.dt * 1000);
                const dateTimeString = `${date.toLocaleDateString("pl-PL")} ${date.toLocaleTimeString("pl-PL")}`;

                const temperature = weather.main.temp;
                const feelsLikeTemperature = weather.main.feels_like;
                const iconName = weather.weather[0].icon;
                const description = weather.weather[0].description;

                const weatherBlock = this.createWeatherBlock(dateTimeString, temperature, feelsLikeTemperature, iconName, description);
                this.resultsBlock.appendChild(weatherBlock);
            }
        }
    }

    createWeatherBlock(dateString, temperature, feelsLikeTemperature, iconName, description) {
const weatherBlock=document.createElement("div");
weatherBlock.className="weather-block";

const dateBlock=document.createElement("div");
dateBlock.className="weather-date";
dateBlock.innerHTML=dateString;
weatherBlock.appendChild(dateBlock);

const temperatureBlock=document.createElement("div");
temperatureBlock.className="weather-temperature";
temperatureBlock.innerHTML=`${temperature} &deg;C`;
weatherBlock.appendChild(temperatureBlock);

const temperatureFeelBlock=document.createElement("div");
temperatureFeelBlock.className="weather-temperature-feels-like";
temperatureFeelBlock.innerHTML=`Odczuwalna: ${feelsLikeTemperature} &deg;C`;
weatherBlock.appendChild(temperatureFeelBlock);

const iconBlock=document.createElement("img");
iconBlock.className="weather-icon";
	iconBlock.src= this.iconLink.replace("{iconName}", iconName);
weatherBlock.appendChild(iconBlock);

const descriptionBlock=document.createElement("div");
descriptionBlock.className="weather-description";
descriptionBlock.innerHTML=description;
weatherBlock.appendChild(descriptionBlock);
return weatherBlock;
    }
}

document.weatherApp = new WeatherApp("f0b3eaa581be2e88d2aa4ed9ed5e771f", "#weather-results-container");

document.querySelector("#checkButton").addEventListener("click", function() {
    const query = document.querySelector("#locationInput").value;
    document.weatherApp.getWeather(query);
});