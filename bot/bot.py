import asyncio
from telethon.sync import TelegramClient, events

class Bot:
	def __init__(self, logs=None, api_id='', api_hash=''):
		print('Creating bot.')

		if logs is None:
			print('Error: Logger is None! (Bot)')
			return False

		# array to save id of users
		self.user_id_list = []
		self.api_id = api_id
		self.api_hash = api_hash
		self.logs = logs

		# create telegram client
		self.client = None
		self.client = TelegramClient(username, api_id, api_hash)
		
		if client is None:
			logs.error('Cannot create telegram client')
			return None
		else:
			logs.error('Created telegram client')

	def RunH8Chat(self, username='', api_id='', api_hash=''):
		if not username or not self.api_id or not self.api_hash:
			self.logs.critical('Data for chat bot is bad (Bot).')
			self.logs.critical('User data: ', username)
			self.logs.critical('API id: ', api_id)
			self.logs.critical('API hash: ', api_hash)
			return False

	def StopH8Chat(self, str_info=''):
		if not str_info:
			self.logs.critical('Why did you stop me (Bot)?')
			return False

	def Statistic(self, user_id='', data=''):
		if not user_id:
			self.logs.critical('User id is empty! (Bot)')
			return False

		if not data:
			self.logs.critical('Data of statistic is empty! (Bot)')
			return False

		self.logs.info('Write statistic of selected user. (Bot)')
		return True