import asyncio
from telethon.sync import TelegramClient, events

class Bot:
	def __init__(self, logs=None, username='', api_id='', api_hash=''):
		if logs is None:
			raise Exception('Error: Logger is None! (Bot)')

		# array to save id of users
		self.user_id_list = []
		self.username = username
		self.api_id = api_id
		self.api_hash = api_hash
		self.logs = logs

		# create telegram client
		self.client = None
		self.client = TelegramClient(self.username, self.api_id, self.api_hash)
		
		if self.client is None:
			raise Exception('Cannot create telegram client')
		else:
			logs.error('Created telegram client')

	def run_H8_chat(self):
		self.client.start()

		#event on new message
		@client.on(events.NewMessage(incoming=True, forwards=None))
		async def handler(event):
			user_info = event.message.to_dict()['from_id']
			user_id = user_info['user_id']
			user_name = event.message

			count = 0
			for i in self.user_id_list:
				if i == user_id:
					count += 1
				else:
					continue

			if count == 0:
				self.user_id_list.append(user_id)
				await asyncio.sleep(1)
				await self.client.send_message(user_id, 'Text')
			print(self.user_id_list)
		
		self.client.run_until_disconnected()

	def stop_H8_chat(self):
		self.client.disconnect()

	def statistic(self):
		pass