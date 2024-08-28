from openai import AzureOpenAI
import json
import time
    
def AzureResonse(content):
    client = AzureOpenAI(
    azure_endpoint = "https://project-python-openai.openai.azure.com/", 
    api_key="52065ab17bad4153b1848e97419fe31f",  
    api_version="2024-02-15-preview"
    )

    try:
        response = client.chat.completions.create(
            model="GPTCompany", # model = "deployment_name".
            messages=[
                {"role": "system", "content": "You are a helpful assistant which will search for company official websites from the company name provided and return the output of the company names in json format."},
                {"role": "user", "content": content},
                # {"role": "assistant", "content": "Yes, customer managed keys are supported by Azure OpenAI."},
                # {"role": "user", "content": "Do other Azure AI services support this too?"}
            ]
        )
        res = response.choices[0].message.content
        res = res.replace('```json\n', '').replace('```', '')
        res = json.loads(res)
        return res
    except Exception as err:
        print('Trying Again.....')
        time.sleep(10)
        AzureResonse(content)


print(AzureResonse("Samsung, Google, Microsoft"))