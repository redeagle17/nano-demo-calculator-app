#include "crow_all.h"

crow::response greet()
{
    return crow::response{"Hello, welcome to the calculator API!"};
}

crow::response add(const crow::request &req)
{
    auto json_data = crow::json::load(req.body);
    
    if (!json_data)
    {
        // Return a bad request response if the JSON data is invalid
        return crow::response(400, "Invalid JSON data");
    }
    
    if (!json_data.has("num1") || !json_data.has("num2"))
    {
        // Return a bad request response if the JSON data does not contain the required fields
        return crow::response(400, "Missing 'num1' or 'num2' in JSON data");
    }

    double num1 = json_data["num1"].d();
    double num2 = json_data["num2"].d();

    double result = num1 + num2;

    crow::json::wvalue response_data;
    response_data["result"] = result;

    return crow::response{response_data};
}

crow::response subtract(const crow::request &req)
{
    auto json_data = crow::json::load(req.body);
    
    if (!json_data)
    {
        // Return a bad request response if the JSON data is invalid
        return crow::response(400, "Invalid JSON data");
    }
    
    if (!json_data.has("num1") || !json_data.has("num2"))
    {
        // Return a bad request response if the JSON data does not contain the required fields
        return crow::response(400, "Missing 'num1' or 'num2' in JSON data");
    }

    double num1 = json_data["num1"].d();
    double num2 = json_data["num2"].d();

    double result = num1 - num2;

    crow::json::wvalue response_data;
    response_data["result"] = result;

    return crow::response{response_data};
}