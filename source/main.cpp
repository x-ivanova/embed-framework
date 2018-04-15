#include "crow.h"
#include "user.cpp"

using namespace std;

int main()
{
    AutoWaterSystem autoWaterSystem = AutoWaterSystem();

    string passMessage = "No auth. Use /?password=password";
    string errMessage = "Wrong password";
    string setMessage = "Example: Use /set/?temperature=20";

    crow::SimpleApp app;
    crow::mustache::set_base(".");

    CROW_ROUTE(app, "/get/")
            ([&autoWaterSystem](){
                crow::json::wvalue response;
                response["power"] = int(autoWaterSystem.isPower());
                response["password"] = autoWaterSystem.getPassword();
                response["plant"] = autoWaterSystem.getPlant();
                response["temperature"] = autoWaterSystem.getTemperature();
                return response;
            });

    CROW_ROUTE(app, "/set/")
            ([&setMessage, &autoWaterSystem](const crow::request& req){
                if(req.url_params.get("password") != nullptr) {
                    string tmp = boost::lexical_cast<string>(req.url_params.get("password"));
                    return autoWaterSystem.changePassword(tmp);
                }
                if(req.url_params.get("plant") != nullptr) {
                    string tmp = boost::lexical_cast<string>(req.url_params.get("plant"));
                    return autoWaterSystem.changePlant(tmp);
                }
                if(req.url_params.get("temperature") != nullptr) {
                    int tmp = boost::lexical_cast<int>(req.url_params.get("temperature"));
                    return autoWaterSystem.changeTemperature(tmp);
                }
                return setMessage;
            });

    CROW_ROUTE(app, "/")
            ([&errMessage, &passMessage, &autoWaterSystem](const crow::request &req){
                if(req.url_params.get("password") != nullptr) {
                    string tmp = boost::lexical_cast<string>(req.url_params.get("password"));
                    return (tmp == autoWaterSystem.getPassword())? crow::mustache::load("index.html").render() : errMessage;
                }
                return passMessage;
            });

    CROW_ROUTE(app, "/shot/")
            ([&autoWaterSystem]{
                return autoWaterSystem.make_shot();
            });

    CROW_ROUTE(app, "/power/")
            ([&autoWaterSystem]{
                return (autoWaterSystem.isPower())?autoWaterSystem.turnOff():autoWaterSystem.turnOn();
            });


    CROW_ROUTE(app, "/<path>")
            ([](string file){
                return crow::mustache::load(file).render();
            });



    app.port(8080).run();



}
