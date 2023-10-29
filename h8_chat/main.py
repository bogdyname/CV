import asyncio
import configparser
from telethon.sync import TelegramClient, events

def Run_H8_Chat(username = '', api_id = '', api_hash = ''):
    if not username or not api_id or not api_hash:
        return False

    # array to save id of user
    user_id_list = []
    
    # create telegram client
    client = TelegramClient(username, api_id, api_hash)
    client.start()

    #event on new message
    @client.on(events.NewMessage(incoming=True, forwards=None))
    async def handler(event):
        user_info = event.message.to_dict()['from_id']
        user_id = user_info['user_id']
        user_name = event.message

        count = 0
        for i in user_id_list:
            if i == user_id:
               count += 1
            else:
                continue

        if count == 0:
            user_id_list.append(user_id)
            await asyncio.sleep(1)
            await client.send_message(user_id, 'Text')
        print(user_id_list)
    
    client.run_until_disconnected()

if __name__ == '__main__':
    log.info('Start main program')

    if not Run_H8_Chat(username, api_id, api_hash):
        print('Config data is empty')