import asyncio
#import logging as log
from telethon.sync import TelegramClient, events

class Bot:
	def __init__(self, api_id='', api_hash=''):
		print('Create bot.')
		# array to save id of user
		self.user_id_list = []
		self.api_id = api_id
		self.api_hash = api_hash

	def RunH8Chat(self, username='', api_id='', api_hash=''):
		if not username or not self.api_id or not self.api_hash:
			log.error('Confgi data for chat is bad.')
			log.error('User data: ', username)
			log.error('API id: ', api_id)
			log.error('API hash: ', api_hash)
			return False

	def Statistic(self, logger, user_id):
		log.info('Write statistic of selected user.')