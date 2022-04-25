import configparser
import pandas as pd

class Config:
	def __init__(self, logger, *args, **kwargs):
		self.filename = 'config.ini'
		self.api_id = ''
		self.api_hash = ''
		self.username = ''

		self.config = configparser.ConfigParser()
		return super().__init__(*args, **kwargs)

def load_config(self, filename = 'config.ini'):
	if filename == '':
		logger.error('Error: filename empty')
		return
	else:
		logger.info('Loading filename: ' + filename)

		#parsing config file
		config.read("config.ini")

		#get metadata
		api_id = config['Telegram']['api_id']
		api_hash = config['Telegram']['api_hash']
		username = config['Telegram']['username']

		logger.info('Api id: ', api_id)
		logger.info('Hash id: ', api_hash)
		logger.info('Username: ', username)