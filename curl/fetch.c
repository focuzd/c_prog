#include <stdio.h>
#include <curl/curl.h>

int main(void) {
    CURL *curl;
    CURLcode res;
    
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://api.github.com");
        // TODO: Add your code here to actually perform the request
        // and print the response to stdout
        // curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "MyCProgram/1.0");

        res = curl_easy_perform(curl);
        printf("\nCurl Result Code: %d\n", res);
        curl_easy_cleanup(curl);
    } 

    else {
        printf("Initialization failed.\n");
    }

    return 0;
}
