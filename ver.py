def compareVersion(self, version1, version2):
	v1 = [int(v) for v in version1.split(".")]
	v2 = [int(v) for v in version2.split(".")]

	for i in range(0, max(len(v1), len(v2))):
		c1 = v1[i] if i < len(v1) else 0
		c2 = v2[i] if i < len(v2) else 0
		if (c1 > c2):
			return 1;
		else if c1 < c2:
			return -1;
		else:
			continue;
	return 0
