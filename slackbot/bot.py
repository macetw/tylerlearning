from flask import Flask
import os
from slack import WebClient
from slackeventsapi import SlackEventAdapter
import random

app = Flask(__name__)
slack_events_adapter = SlackEventAdapter(os.environ.get("SLACK_EVENTS_TOKEN"), "/slack/events", app)
slackwebclient = WebClient(token=os.environ.get("SLACKBOT_TOKEN"))
MESSAGE_BLOCK = { "type": "section", "text": { "type": "mrkdwn", "text": "" } }



@slack_events_adapter.on("message")
def message(payload):
    event = payload.get("event", {})
    text = event.get("text")
    channel_id = event.get("channel")

    if "flip a coin" in text.lower():
        rand_int = random.randint(0,1)
        message = f"A random number: {rand_int}"

        MESSAGE_BLOCK["text"]["text"] = message
        message_to_send = {"channel": channel_id, "blocks": [MESSAGE_BLOCK]}
        return slackwebclient.chat_postMessage(**message_to_send)

    if "widgets" in text.lower():
        header_block = { "type": "header",
                         "text": {
                             "type": "plain_text",
                             "text": "Foobar request",
                             "emoji": True
                        } }
        sectionA_block = { "type": "section",
                           "fields": [ { "type": "mrkdwn",
                                         "text": "*Type:*\nIs _this_ markdown?" },
                                       { "type": "mrkdwn",
                                         "text": "*Created by:* <macetw.com|Tyler Mace>" }
                                     ]
                         }
        sectionB_block = { "type": "section",
                           "fields": [ { "type": "mrkdwn",
                                         "text": "*Asking about:* time off request in example" }
                                     ]
                         }
        widgets_block = { "type": "actions",
                          "elements": [
                              { "type": "button",
                                "text": {
                                    "type": "plain_text",
                                    "emoji": True,
                                    "text": "Approve"
                                },
                                "style": "primary",
                                "value": "click_me_123"
                              },
                              { "type": "button",
                                "text": {
                                    "type": "plain_text",
                                    "emoji": True,
                                    "text": "Reject"
                                },
                                "style": "danger",
                                "value": "click_me_123"
                              }
                          ]
                        }
        message_to_send = {"channel": channel_id, "blocks": [header_block, sectionA_block, sectionB_block, widgets_block]}
        return slackwebclient.chat_postMessage(**message_to_send)


#@app.route('/')
#def hello_world():
#    return 'helloworld.'

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=8080)

