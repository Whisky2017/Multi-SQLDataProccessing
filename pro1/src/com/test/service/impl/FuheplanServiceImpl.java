package com.test.service.impl;

import com.test.dao.FuheplanDao;
import com.test.pojo.Fuheplan;
import com.test.service.FuheplanService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

/**
 * Created by 世康 on 2016/9/19.
 */
@Service(value = "FuheplanService")
public class FuheplanServiceImpl implements FuheplanService {

    @Autowired
    private FuheplanDao fuheplanDao;

    @Override
    public List<Fuheplan> getFuheplanAll() {
        return fuheplanDao.getFuheplanAll();
    }

    @Override
    public List<Fuheplan> getFuheplan(int currentPaging, int pageSize) {
        return fuheplanDao.getFuheplan(currentPaging, pageSize);
    }

    @Override
    public Fuheplan getFuheplanById(String id) {
        return fuheplanDao.getFuheplanById(id);
    }

    @Override
    public int getFuheplanCount() {
        return fuheplanDao.getFuheplanCount();
    }
}
