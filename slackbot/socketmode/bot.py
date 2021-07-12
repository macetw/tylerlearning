import os
import re
from slack_bolt import App
from slack_bolt.adapter.socket_mode import SocketModeHandler

app = App(token=os.environ["SLACK_BOT_TOKEN"])
#      not needed on socket mode
#          signing_secret=os.environ["SLACK_SIGNING_SECRET"])


@app.message(re.compile("coin ([0-9]+)"))
def message_hello(message, say, context):
    coins = context['matches'][0]
    say(f"Hey there <@{message['user']}>!")
    say(f"I have {coins} coins.")


if __name__ == "__main__":
    handler = SocketModeHandler(app, os.environ["SLACK_APP_TOKEN"])
    handler.start()
